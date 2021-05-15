// MiAttachSession 
 
int __fastcall MiAttachSession(int a1)
{
  int result; // r0
  int v2; // r4
  int v3; // r3

  *(_DWORD *)(*(_DWORD *)((__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) + 0x74) + 324) = a1;
  result = MiAttachTrimmerToSession();
  v2 = dword_633784;
  __dmb(0xFu);
  v3 = KiTbFlushTimeStamp;
  __dmb(0xBu);
  if ( (unsigned int)(v3 - v2) <= 2 )
  {
    result = v2 & 1;
    if ( (v2 & 1) != 0 || (unsigned int)(v3 - v2) < 2 )
    {
      if ( (v3 & 1) != 0 )
        result = sub_51DD38(result, &KiTbFlushTimeStamp);
      else
        result = KeFlushTb(1, 0);
    }
  }
  return result;
}
