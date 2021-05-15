// ObpCompareEntryLevel1 
 
int __fastcall ObpCompareEntryLevel1(int a1, _DWORD *a2)
{
  int v3; // r3
  int v4; // r0
  int result; // r0

  v3 = a2[3];
  a2[2] = a1;
  a2[3] = v3 + 1;
  v4 = RtlEnumerateBoundaryDescriptorEntries(
         (_DWORD *)(a2[1] + 24),
         (int (__fastcall *)(_DWORD *, int))ObpCompareEntryLevel2,
         (int)a2);
  if ( v4 < 0 )
  {
    a2[5] = v4;
    JUMPOUT(0x7EF794);
  }
  if ( a2[3] == a2[4] )
    result = 1;
  else
    result = sub_7EF790();
  return result;
}
