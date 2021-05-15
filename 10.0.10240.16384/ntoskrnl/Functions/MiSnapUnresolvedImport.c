// MiSnapUnresolvedImport 
 
int __fastcall MiSnapUnresolvedImport(int a1, int *a2, int a3, int a4)
{
  int v6; // r0
  int result; // r0
  int v8; // r2
  int v9[4]; // [sp+0h] [bp-10h] BYREF

  v9[0] = a4;
  v6 = RtlImageDirectoryEntryToData(a3, 1, 0, (int)v9);
  if ( !v6 )
    return 0;
  v8 = *a2;
  if ( *a2 >= 0 )
    result = v8 + a1 + 2;
  else
    result = (unsigned __int16)(v8 - *(_DWORD *)(v6 + 16));
  return result;
}
