SHELL = /bin/sh

#install directory
DEST  = /usr/local/qlwm
MANPATH = /usr/local/man
# MANPATH = /usr/local/share/man
QMAKE = qmake-qt4
# QMAKE = /usr/local/qt/bin/qmake

DVERSION = 4.3

all: config
	cd src    ; $(QMAKE) qlwm.pro   ; $(MAKE)
	cd dclock ; $(QMAKE) dclock.pro ; $(MAKE)
	cd mail   ; $(QMAKE) biff.pro   ; $(MAKE)

config: Makefile
	cd files ; \
	sed -e s%@BASEDIR@%$(DEST)%g < defaults.in > defaults
	cd src ; \
	(echo "#define CONFDIR \"$(DEST)/files/\"" ; \
	echo "#define DVERSION \"$(DVERSION)\n\"") > conf.h
	cd mail ; \
	for i in /var/spool/mail /var/mail /usr/spool/mail /usr/mail ; do [ -d $${i} ] && break ; done ; \
	echo "#define MAILDIR \"$${i}/\"" | tee conf.h  
	touch config

clean:
	rm -f config files/defaults
	cd src ; $(MAKE) clean 
	cd dclock ; $(MAKE) clean
	cd mail ; $(MAKE) clean

dist: 
	rm -f src/Makefile dclock/Makefile mail/Makefile ; \
	find * -exec touch {} \; ; \
	d=qlwm-$(DVERSION) ; \
	cd .. ; \
	rm -f $${d}.tar.gz ; \
	ln -s qlwm $${d} ; \
	tar cvzhf $${d}.tar.gz $${d} ; \
	rm $${d}

install: all
	mkdir -p $(DEST)/files
	cd src    ; install -o root -s ./qlwm $(DEST)/qlwm
	cd dclock ; install -o root -s ./dclock $(DEST)/dclock
	cd mail   ; install -o root -s ./biff $(DEST)/biff
	install -c ./README $(DEST)/README
	install -c ./qlwm.1 $(MANPATH)/man1/qlwm.1
	ln -sf $(DEST)/qlwm /usr/local/bin/qlwm
	cp files/* $(DEST)/files 

install-config:	
	mkdir -p $${HOME}/.qlwm
	for i in defaults appdefaults menuconfig; \
		do cp -v files/$${i} $${HOME}/.qlwm; \
	done
