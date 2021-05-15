// CmpCmdRenameHive 
 
int __fastcall CmpCmdRenameHive(int a1, int a2, unsigned __int16 *a3, int a4, char a5)
{
  int v6; // r4
  int v7; // r0
  unsigned int v8; // r5
  unsigned __int16 *varg_r2; // [sp+30h] [bp+10h]

  varg_r2 = a3;
  if ( !a2 || (v6 = ZwQueryObject(), v6 >= 0) )
  {
    v7 = ExAllocatePoolWithTag(1, *a3 + 16, 538987843);
    v8 = v7;
    if ( v7 )
    {
      *(_BYTE *)v7 = a5;
      *(_DWORD *)(v7 + 4) = 0;
      *(_DWORD *)(v7 + 8) = *a3;
      memmove(v7 + 12, *((_DWORD *)a3 + 1), *a3);
      v6 = ZwSetInformationFile();
      ExFreePoolWithTag(v8);
    }
    else
    {
      v6 = -1073741670;
    }
  }
  return v6;
}
