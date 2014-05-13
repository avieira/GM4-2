#!/usr/bin/env python2.7
import os,subprocess,pynotify,pyinotify
from gobject import GError

def auto_compile(path):
	wm = pyinotify.WatchManager()
	notifier = pyinotify.Notifier(wm)
	wm.add_watch(path, pyinotify.IN_CLOSE_WRITE,onSave)
	notifier.loop()
	
def onSave(event):
	if ".tex" in event.name:
		pynotify.init("Mon appli python")
		try:
			subprocess.check_call(['mkdir', '-p', 'tmp'])
			#Entre machine INSA et maison : inverser les commentaires du bloc suivant
			subprocess.check_call(['latexmk', '-pdf', '-shell-escape' ,'-halt-on-error' ,'Rapport.tex'])
			#subprocess.check_call(['latexmk', '-pdf', '-output-directory=tmp', '-shell-escape' ,'-halt-on-error' ,'Rapport.tex'])
			#subprocess.check_call(['mv', 'tmp/Rapport.pdf', '.'])

			#subprocess.check_call(['latexmk', '-shell-escape', '-pdf', 'rapport.tex'])
			#subprocess.check_call(['mv', '*.aux', '*.toc', 'tmp'])


		except subprocess.CalledProcessError:
			message = pynotify.Notification("Build failed.")
		else:
			message = pynotify.Notification("Build done.")
		try:
			message.show()
		except GError:
			print('Gerror')

def main():
	auto_compile([x[0] for x in os.walk(os.getcwd())])

if __name__ == '__main__':
    main()


