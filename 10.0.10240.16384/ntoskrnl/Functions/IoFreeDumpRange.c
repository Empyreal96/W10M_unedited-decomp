// IoFreeDumpRange 
 
int __fastcall IoFreeDumpRange(_DWORD *a1, int a2, int a3, int a4)
{
  int v4; // r8
  unsigned int v5; // r7
  int v7; // r0
  int v8; // r4
  int v9; // r0
  __int64 v11[4]; // [sp+8h] [bp-20h] BYREF

  v4 = a3;
  v5 = a2;
  if ( a4 == 1 )
  {
    MmGetPhysicalAddress((int)v11, a2, a3, 1);
    v7 = IopRemovePageFromPageMap(a1[2], a1[3], v11[0] >> 12, v4, (a1[4] & 1) != 0);
LABEL_5:
    v8 = v7;
    goto LABEL_11;
  }
  if ( a4 == 2 )
  {
    v7 = IopRemovePageFromPageMap(a1[2], a1[3], a2, a3, (a1[4] & 1) != 0);
    goto LABEL_5;
  }
  v8 = 0;
  if ( !a3 )
    return v8;
  do
  {
    if ( MiIsAddressValid(v5, 0, a3, a4) )
    {
      MmGetPhysicalAddress((int)v11, v5, a3, a4);
      v9 = IopRemovePageFromPageMap(a1[2], a1[3], v11[0] >> 12, 1, (a1[4] & 1) != 0);
      if ( v9 < 0 )
        v8 = v9;
    }
    v5 += 4096;
    --v4;
  }
  while ( v4 );
LABEL_11:
  if ( v8 == -1073741503 && (a1[4] & 1) != 0 )
    v8 = 0;
  return v8;
}
