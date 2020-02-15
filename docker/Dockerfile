FROM ros:melodic-perception-bionic

COPY ./.bashrc ./generate-clang-tidy-report.sh /root/

RUN apt update && apt upgrade -y
RUN apt install -y bash-completion vim libtinyxml-dev clang-9 clang-format-9 clang-tidy-9 clang-tools-9 doxygen graphviz
RUN mkdir -p /usr/src/catkin_ws/src
RUN git clone -b dev http://github.com/juliencombattelli/ontologenius /usr/src/catkin_ws/src/ontologenius
RUN git clone http://github.com/sarthou/ontologenius_query /usr/src/catkin_ws/src/ontologenius_query

WORKDIR /usr/src/catkin_ws
CMD ["bash"]
