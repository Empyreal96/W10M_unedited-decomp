// RtlFindExportedRoutineByName 
 
unsigned int __fastcall RtlFindExportedRoutineByName(int a1, int a2, int a3, int a4)
{
  _DWORD *v5; // r0
  _DWORD *v6; // r4
  int v7; // r8
  int v8; // r10
  int v9; // r9
  int v10; // r5
  int v11; // r6
  signed int v12; // r0
  unsigned int v13; // r2
  unsigned int result; // r0
  int v16[9]; // [sp+4h] [bp-24h] BYREF

  v16[0] = a3;
  v16[1] = a4;
  v5 = (_DWORD *)RtlImageDirectoryEntryToData(a1, 1, 0, (int)v16);
  v6 = v5;
  if ( !v5 )
    return 0;
  v7 = 0;
  v8 = v5[8] + a1;
  v9 = v5[9] + a1;
  v10 = v5[6] - 1;
  if ( v10 < 0 )
    return 0;
  do
  {
    v11 = (v10 + v7) >> 1;
    v12 = strcmp(a2, (unsigned int *)(*(_DWORD *)(v8 + 4 * v11) + a1));
    if ( v12 < 0 )
    {
      if ( !v11 )
        return 0;
      v10 = v11 - 1;
      continue;
    }
    if ( v12 <= 0 )
      break;
    v7 = v11 + 1;
  }
  while ( v10 >= v7 );
  if ( v10 < v7 )
    return 0;
  v13 = *(unsigned __int16 *)(v9 + 2 * v11);
  if ( v13 >= v6[5] )
    return 0;
  result = *(_DWORD *)(v6[7] + 4 * v13 + a1) + a1;
  if ( result > (unsigned int)v6 && result < (unsigned int)v6 + v16[0] )
    return 0;
  return result;
}
