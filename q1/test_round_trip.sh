#!/bin/bash

set -e

g++ disassembler_labels.cpp mu0_disassembly.cpp -o disassembler_labels
g++ assembler_finale.cpp mu0_assembly.cpp -o assembler_reworked

<prog1.mu0.bin ./disassembler_labels >prog1_intermediate.asm
<prog1_intermediate.asm ./assembler_reworked >prog1.final.bin

diff --ignore-space-change prog1.final.bin prog1.mu0.bin

echo "Success"


