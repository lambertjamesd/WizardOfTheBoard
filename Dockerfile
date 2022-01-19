from node:16.13.2-slim as wizard_of_the_board_setup

WORKDIR /usr/src/app

ENV N64_LIBGCCDIR /opt/crashsdk/lib/gcc/mips64-elf/11.2.0
ENV PATH /opt/crashsdk/bin:$PATH
ENV ROOT /etc/n64

RUN apt update -y
RUN apt install -y ca-certificates

RUN echo "deb [trusted=yes] https://crashoveride95.github.io/apt/ ./" | tee /etc/apt/sources.list.d/n64sdk.list
RUN apt update -y

RUN dpkg --add-architecture i386

RUN apt install -y binutils-mips-n64 \
    gcc-mips-n64 \
    libgcc-mips-n64 \
    n64sdk \
    makemask \
    root-compatibility-environment \
    build-essential \
    libmpc-dev \
    libnustd \
    libnusys \
    libnaudio \
    gperf

COPY maps maps

RUN npm install --prefix ./maps

from wizard_of_the_board_setup as wizard_of_the_board

# avoid copying the .git folder since it is huge
COPY asm asm
COPY audio audio
COPY bip-mapping bip-mapping
COPY cast_sprites cast_sprites
COPY cutscene_backgrounds cutscene_backgrounds
COPY cutscenes cutscenes
COPY dialogue dialogue
COPY doc doc
COPY opening opening
COPY release release
COPY sprites sprites

COPY bishop.c credits.h debug.h graphic.h LICENSE nustdfuncs.c projectile.c sixtwelve.c splashscreen.c titlescreen.c \
    board.c cursor.c gameaudio.c jam2.ld main.c nustdfuncs.h queen.c sixtwelve.h splashscreen.h titlescreen.h \
    backgroundbuffers.c board.h dialogue.c gameaudio.h jumper.c main.h ogre.c README.md sixtwelve_helpers.c toad.c \
    backgroundbuffers.h buildwithlevels.sh cutscene.c dialogue.h gamemath.c king.c Makefile sixtwelve_helpers.h stage00.c usb.c \
    betweenstages.c cutscene.h displaytext.c gamemath.h knight.c mapdata.h pawn.c rook.c sixtwelve_tex.c stage00.h usb.h \
    betweenstages.h constants.h displaytext.h gfxinit.c levelselect.c maps pieces.c segmentinfo.h snake.c stagekeys.c wall.c \
     credits.c debug.c graphic.c levelselect.h monsters.h pieces.h shadowqueen.c sound_data.s stagekeys.h \
    ./

CMD ./buildwithlevels.sh