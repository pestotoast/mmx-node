FROM ubuntu
RUN apt update && \
    DEBIAN_FRONTEND=noninteractive TZ=Etc/UT apt install -y git cmake build-essential libsecp256k1-dev librocksdb-dev libsodium-dev zlib1g-dev ocl-icd-opencl-dev clinfo && \
    apt install -y intel-opencl-icd beignet-opencl-icd && \
    git clone https://github.com/madMAx43v3r/mmx-node.git && \
    cd mmx-node && \
    git submodule update --init --recursive && \
    ./make_devel.sh && \
    chmod +x run_node.sh && \
    useradd -d /mmx-node -u 11337 -s /usr/sbin/nologin mmx && \
    chown -R mmx:mmx /mmx-node 
WORKDIR /mmx-node
USER mmx
ENTRYPOINT /mmx-node/run_node.sh
