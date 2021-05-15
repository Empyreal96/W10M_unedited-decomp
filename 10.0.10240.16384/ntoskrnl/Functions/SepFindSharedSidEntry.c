// SepFindSharedSidEntry 
 
int __fastcall SepFindSharedSidEntry(unsigned __int16 *a1, int a2, int a3, int a4)
{
  int v5; // r5
  int v6; // r0
  _DWORD *v7; // r6
  int i; // r0
  int v9; // r4
  _DWORD v11[8]; // [sp+0h] [bp-20h] BYREF

  v11[0] = a1;
  v11[1] = a2;
  v11[2] = a3;
  v11[3] = a4;
  v5 = 0;
  v6 = SepComputeSidSignature((int)a1);
  v7 = g_SepSidMapping;
  for ( i = RtlLookupEntryHashTable(*((_DWORD **)g_SepSidMapping + 1), v6, v11, (int)&g_SepSidMapping);
        ;
        i = RtlGetNextEntryHashTable(v7[1], (int)v11) )
  {
    v9 = i;
    if ( !i )
      break;
    if ( RtlEqualSid(a1, *(unsigned __int16 **)(i + 16)) )
      return v9;
  }
  return v5;
}
