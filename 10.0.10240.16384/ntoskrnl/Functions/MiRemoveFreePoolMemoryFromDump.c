// MiRemoveFreePoolMemoryFromDump 
 
int __fastcall MiRemoveFreePoolMemoryFromDump(int result)
{
  int v1; // r7
  unsigned int v2; // r4
  _DWORD *v3; // r5
  int v4; // r4
  int v5[6]; // [sp+0h] [bp-30h] BYREF
  char v6; // [sp+18h] [bp-18h]

  v5[0] = 2;
  v5[5] = 0;
  v6 = 1;
  v1 = result;
  v2 = 0;
  for ( v5[4] = result; v2 < (unsigned __int16)KeNumberNodes; result = MiScanNonPagedPoolVa(1, v2++, 0, (int)v5) )
    ;
  v3 = (_DWORD *)dword_632A94;
  if ( dword_632A94 )
  {
    do
    {
      v4 = (int)v3 - MmPfnDatabase;
      v3 = (_DWORD *)*v3;
      result = (*(int (__fastcall **)(int, int, int, int, int))(v1 + 4))(v1, v4 / 24, 1, 2, v5[0]);
    }
    while ( v3 );
  }
  return result;
}
