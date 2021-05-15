// ExpAllocateMidLevelTable 
 
int __fastcall ExpAllocateMidLevelTable(int a1, int *a2, int a3, int a4)
{
  int *v6; // r4
  int v7; // r0
  int varg_r0; // [sp+18h] [bp+8h]
  int *varg_r1; // [sp+1Ch] [bp+Ch]

  varg_r0 = a1;
  varg_r1 = a2;
  v6 = (int *)ExpAllocateTablePagedPool(*(_DWORD *)(a1 + 12), 4096);
  if ( !v6 )
    JUMPOUT(0x7DDA84);
  v7 = ExpAllocateLowLevelTable(a1, a3);
  *a2 = v7;
  if ( !v7 )
    return sub_7DDA78();
  *v6 = v7;
  return (int)v6;
}
