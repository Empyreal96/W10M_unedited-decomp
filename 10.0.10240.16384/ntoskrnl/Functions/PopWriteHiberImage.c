// PopWriteHiberImage 
 
int __fastcall PopWriteHiberImage(int result, char a2, int a3)
{
  int *v3; // r3
  int v4; // r7
  int v5; // r6
  int v6; // r10
  unsigned int v8; // r5
  int v9; // r4
  int v10; // r3
  BOOL v11; // r8
  int v12[2]; // [sp+10h] [bp-C8h] BYREF
  char v13[12]; // [sp+18h] [bp-C0h] BYREF
  int v14; // [sp+24h] [bp-B4h]
  char v15[96]; // [sp+78h] [bp-60h] BYREF

  v3 = &PopHiberInfo;
  v4 = *(_DWORD *)(result + 164);
  v5 = 0;
  v6 = dword_61EF00;
  v8 = result;
  v9 = 0;
  do
  {
    PopHiberCheckForDebugBreak(result, a2, a3, (int)v3);
    v11 = PopRequestWrite(v8, v6, 1, v10);
    if ( !v9 )
    {
      result = PopGetNextTable(v8, v12, (int)v15, (unsigned int)v13, a2, *(_DWORD *)(v4 + 4));
      v5 = result;
      if ( !result )
        continue;
      *(_QWORD *)(v4 + 40) += (unsigned int)result;
      v9 = PopAddPagesToCompressedPageSet(v8, v4, v12, v14, a2, result, (int)PopCompressCallback);
    }
    result = PopCountDataAsProduced(v4, v9, v12, (int)v15, v5, 1);
    if ( result )
      v9 = 0;
  }
  while ( !v11 );
  return result;
}
