// PopSetRange 
 
int __fastcall PopSetRange(int a1, int a2, const void *a3, const void *a4, int a5)
{
  int varg_r0; // [sp+28h] [bp+8h]
  int varg_r1; // [sp+2Ch] [bp+Ch]
  const void *varg_r2; // [sp+30h] [bp+10h]
  const void *varg_r3; // [sp+34h] [bp+14h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  varg_r3 = a4;
  if ( (PoDebug & 0x80) != 0 )
    DbgPrint("PopSetRange: Type %04x  StartPage: %p PageCount: %p  Tag: %.4s\n", a2, a3, a4, (const char *)&a5);
  if ( *(_BYTE *)(a1 + 20) )
  {
    PopInternalAddToDumpFile(a1, 312, 0);
    KeBugCheckEx(160, 260, 10, a1, 0);
  }
  if ( (a2 & 0x8000) != 0 )
    return PopDiscardRange(a1, a3, a4, a5);
  if ( (a2 & 2) != 0 )
    return PopCloneRange(a1, a3, a4, a5);
  if ( (a2 & 0x10000) == 0 )
  {
    PopInternalAddToDumpFile(a1, 312, 0);
    KeBugCheckEx(160, 261, 10, a1, 0);
  }
  return PopSetBootPhaseRange(a1, a3, a4, a5);
}
