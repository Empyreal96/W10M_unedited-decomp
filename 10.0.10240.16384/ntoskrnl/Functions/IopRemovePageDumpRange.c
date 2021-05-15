// IopRemovePageDumpRange 
 
int __fastcall IopRemovePageDumpRange(_DWORD *a1, char *a2)
{
  int v3; // r2
  int result; // r0
  char v5; // r6
  int v6; // r2
  int v7; // r1
  int v8; // r3
  int v9; // r2
  int v10; // r0
  _DWORD v11[2]; // [sp+0h] [bp-30h] BYREF
  _DWORD v12[2]; // [sp+8h] [bp-28h] BYREF
  _DWORD *v13; // [sp+10h] [bp-20h]
  int v14; // [sp+14h] [bp-1Ch]
  int v15; // [sp+18h] [bp-18h]

  v12[0] = 0;
  v12[1] = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  if ( a2 )
    *a2 = 0;
  v3 = a1[1];
  if ( (v3 & 0x7FFFFFFC) != 0 )
    return -1073741582;
  if ( v3 >= 0 )
  {
    v5 = 0;
  }
  else
  {
    a1[1] = v3 & 0x7FFFFFFF;
    v5 = 1;
  }
  v6 = a1[1];
  if ( ((v6 - 1) & v6) != 0 )
    return -1073741811;
  if ( !a1[4] )
    return 0;
  if ( (v6 & 1) != 0 )
  {
    v7 = a1[3];
    v8 = 0;
  }
  else
  {
    v8 = 2;
    v7 = a1[3] >> 12;
  }
  v9 = a1[4];
  v10 = *(_DWORD *)(CrashdmpDumpBlock + 8);
  v11[0] = *(_DWORD *)(v10 + 48);
  v11[1] = v10 + 56;
  v13 = v11;
  result = IoFreeDumpRange(v12, v7, v9, v8);
  if ( result >= 0 )
  {
    if ( a2 )
      *a2 = v5;
  }
  return result;
}
