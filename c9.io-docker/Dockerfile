FROM ubuntu
MAINTAINER xml@live.com

ENV USERNAME ""
ENV PASSWORD ""
ENV DEBIAN_FRONTEND noninteractive

RUN cd /root && \
	apt-get update && \
	apt-get upgrade -y && \
	apt-get install -y nodejs npm git wget python3 make ruby-full cmake gcc g++ golang zlib1g zlib1g.dev apache2 php7.2-curl php7.2-json php7.2-cgi php7.2 libapache2-mod-php7.2 openjdk-8-jdk-headless locales mysql-server mysql-common mysql-client phpmyadmin && \
	apt-get clean && \
	git clone https://github.com/c9/core.git core && \
	locale-gen "en_US.UTF-8" && \
	cd core && \
	gem install rails -V && \
	curl https://install.meteor.com | sh && \
	npm install --global coffeescript && \
	npm install --global mocha && \
	npm install && \
	/bin/bash ./scripts/install-sdk.sh && \
	mkdir -p /root/workingdir && \
	cd /root/workingdir && \
	/etc/init.d/mysql start && \
	mysqladmin -u root password c9iodocker && \
	/etc/init.d/mysql stop && \
	ln -s /var/www/ ./www && \
	ln -s /etc/apache2/ ./apache2-conf && \
	ln -s /usr/share/phpmyadmin/ /var/www/phpmyadmin
EXPOSE 8181
EXPOSE 80
VOLUME /root/workingdir

CMD /bin/sh -c "/etc/init.d/apache2 start && /etc/init.d/mysql start && node /root/core/server.js -w /root/workingdir --listen 0.0.0.0 --port 8181 -a $USERNAME:$PASSWORD"
