FROM ubuntu:18.04


RUN apt-get update -yqq && \
    apt-get install -y wget dpkg && \
    wget https://vscode-update.azurewebsites.net/latest/linux-deb-x64/stable -O /tmp/code_latest_amd64.deb&& \
    apt install -y /tmp/code_latest_amd64.deb \
    # dpkg -i /tmp/code_latest_amd64.deb \
    # install Packages
    && apt-get install -yqq vim make cmake avr-libc binutils-avr gcc-avr avrdude build-essential libserial-dev libboost-dev libgtk2.0-0 libxss1 libasound2\
    && rm -rf /var/lib/apt/lists 

RUN useradd -ms /bin/bash nirnai
USER  nirnai
RUN mkdir /home/nirnai/avr
WORKDIR /home/nirnai/avr

ENTRYPOINT [ "code", "project" ]