FROM ubuntu:22.04

ARG TARGETOS
ARG TARGETARCH

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update

ARG USERNAME=jinayp
ARG USER_UID=1000
ARG USER_GID=$USER_UID

RUN groupadd --gid $USER_GID $USERNAME \
    && useradd --uid $USER_UID --gid $USER_GID -ms /bin/bash $USERNAME \
    #
    # [Optional] Add sudo support. Omit if you don't need to install software after connecting.
    && apt-get update \
    && apt-get install -y sudo \
    && echo $USERNAME ALL=\(root\) NOPASSWD:ALL > /etc/sudoers.d/$USERNAME \
    && chmod 0440 /etc/sudoers.d/$USERNAME


# Installation of dev environment dependencies
RUN apt-get install -y \
    gcc g++ clang-format clang-tidy lcov \
    wget git git-lfs \
    openjdk-11-jdk openjdk-11-jre \
    graphviz vim doxygen plantuml \
    cppcheck python3 python3-pygments python-is-python3 python3-pip \
    librdmacm-dev libmlx5-1 software-properties-common gnupg gnupg2 libgl-dev libegl-dev libusb-1.0-0 libglu1

# Installation of Bazel Package
RUN wget https://github.com/bazelbuild/bazelisk/releases/download/v1.11.0/bazelisk-${TARGETOS}-${TARGETARCH} && \
    chmod +x bazelisk-${TARGETOS}-${TARGETARCH} && \
    mv bazelisk-${TARGETOS}-${TARGETARCH} /usr/bin/bazel

# Installation of Bazel Tools
RUN wget https://github.com/bazelbuild/buildtools/releases/download/5.1.0/buildifier-${TARGETOS}-${TARGETARCH} && \
    chmod +x buildifier-${TARGETOS}-${TARGETARCH} && \
    mv buildifier-${TARGETOS}-${TARGETARCH} /usr/bin/buildifier

# Installation of JUnit Merge Tool
RUN wget https://github.com/drazisil/junit-merge/releases/download/v2.0.0/junit-merge-${TARGETOS} && \
    chmod +x junit-merge-${TARGETOS} && \
    mv junit-merge-${TARGETOS} /usr/bin/junit-merge

# cleanup
RUN apt-get clean && rm -rf /var/lib/apt/lists/* && \
    apt-get autoremove -y && apt-get autoclean -y

# [Optional] Set the default user. Omit if you want to keep the default as root.
USER $USERNAME
WORKDIR /home/${USERNAME}
ENTRYPOINT [ "/bin/bash", "-c", "/bin/bash" ]
