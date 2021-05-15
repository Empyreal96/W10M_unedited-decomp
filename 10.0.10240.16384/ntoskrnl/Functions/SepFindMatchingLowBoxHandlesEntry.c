// SepFindMatchingLowBoxHandlesEntry 
 
int __fastcall SepFindMatchingLowBoxHandlesEntry(_DWORD *a1, unsigned __int16 *a2, int *a3, int a4)
{
  unsigned int v7; // r0
  int v8; // r3
  int v9; // r0
  int v10; // r4
  _DWORD v12[8]; // [sp+0h] [bp-20h] BYREF

  v12[3] = a4;
  v12[0] = 0;
  v12[1] = 0;
  v12[2] = 0;
  v7 = SepComputeSidSignature(a2);
  v9 = RtlLookupEntryHashTable(a1, v7, v12, v8);
  v10 = v9;
  if ( !v9 )
  {
    *a3 = 0;
    return 0;
  }
  if ( RtlEqualSid(a2, *(unsigned __int16 **)(v9 + 16)) )
  {
    *a3 = v10;
    return 0;
  }
  return sub_51BAF4();
}
