FROM ubuntu
RUN apt update && \
        DEBIAN_FRONTEND=noninteractive TZ=Etc/UT apt install -y git cmake build-essential libsecp256k1-dev libsodium-dev zlib1g-dev ocl-icd-opencl-dev clinfo 
RUN git clone https://github.com/madMAx43v3r/mmx-node.git && \
    cd mmx-node && \
    git submodule update --init --recursive && \
    ./make_devel.sh && \
    apt install -y intel-opencl-icd beignet-opencl-icd && \
   chmod +x run_node.sh
WORKDIR /mmx-node
ENTRYPOINT /mmx-node/run_node.sh
