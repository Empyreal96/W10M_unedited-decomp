// MiMakeProtoTransition 
 
int __fastcall MiMakeProtoTransition(_DWORD *a1)
{
  unsigned int v1; // r2
  int v2; // r5
  unsigned int v3; // r4
  unsigned int *v4; // r4
  unsigned int v5; // r5

  v1 = a1[2];
  if ( (v1 & 0x400) != 0 )
    v2 = (*(unsigned __int16 *)((a1[2] & 0xFFFFF800 | (2 * (a1[2] & 0x3FC))) + 0x10) >> 1) & 0x1F;
  else
    v2 = (v1 >> 5) & 0x1F;
  v3 = a1[1] | 0x80000000;
  v4 = (unsigned int *)(MiMapPageInHyperSpaceWorker(a1[5] & 0xFFFFF, 0, 0x80000000) + 4 * ((v3 >> 2) & 0x3FF));
  v5 = *v4 & 0xFFFFF81C | (32 * (v2 & 0x1F | 0x40));
  if ( (unsigned int)v4 >= 0xC0000000 )
    return sub_53ABB8();
  *v4 = v5;
  return MiUnmapPageInHyperSpaceWorker(v4, 17, 0x80000000);
}
