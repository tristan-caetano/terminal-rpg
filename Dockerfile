# Starting from an arch linux image
FROM archlinux:base-devel AS base

# Creating working directory
WORKDIR /termrpg

# Copying all of the files from source to working dir
COPY . .

# Running ls to verify all files exist in working dir (can be deleted)
RUN ls

# Running ls to verify we are in working dir (can be deleted)
RUN pwd

# Compiling C++ project
RUN g++ Main.cpp Tree.cpp FightPhase.cpp -o termrpg

# Running program
CMD ["./termrpg"]

# This causes program to loop infinitely without waiting for user input
# RUN ./termrpg
