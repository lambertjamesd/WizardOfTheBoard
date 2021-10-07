
#ifndef SEGMENTINFO_H
#define SEGMENTINFO_H

extern char _codeSegmentStart[];         /* code segment start */
extern char _codeSegmentBssEnd[];           /* code segment end */

extern u8 _seqSegmentRomStart[];
extern u8 _seqSegmentRomEnd[];
extern u8 _midibankSegmentRomStart[];
extern u8 _midibankSegmentRomEnd[];
extern u8 _miditableSegmentRomStart[];
extern u8 _miditableSegmentRomEnd[];

#endif /* SEGMENTINFO_H */
