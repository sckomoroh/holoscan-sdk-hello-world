FROM nvcr.io/nvidia/clara-holoscan/holoscan:v2.6.0-dgpu as holoscan-sdk

RUN apt update
RUN apt install -y vim mc

# Install OpenSSH server
RUN apt update && \
    apt install -y vim mc openssh-server && \
    mkdir -p /var/run/sshd && \
    mkdir -p /root/.ssh && \
    chmod 700 /root/.ssh

RUN echo "root:123" | chpasswd  # Set root password
RUN echo "PermitRootLogin yes" >> /etc/ssh/sshd_config

EXPOSE 22

WORKDIR /ws
