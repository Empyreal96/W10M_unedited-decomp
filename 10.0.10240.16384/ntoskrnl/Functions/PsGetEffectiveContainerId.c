// PsGetEffectiveContainerId 
 
int __fastcall PsGetEffectiveContainerId(int a1, int a2, int a3)
{
  int v6; // r2
  int v7; // r3
  _DWORD *v9; // r2
  _DWORD *v10; // r3
  _DWORD *v11; // r4
  int v12; // r0
  int v13; // r1
  int v14; // r2
  int v15; // r3

  if ( a1 >= 5 )
    return -1073741585;
  if ( a2 )
  {
    memset((_BYTE *)a3, 0, 20);
    if ( (__get_CPSR() & 0x80) != 0 )
    {
      v6 = 0;
    }
    else
    {
      __disable_irq();
      v6 = 1;
    }
    v7 = *(_DWORD *)(((unsigned int)KeGetPcr() & 0xFFFFF000) + 0xC5C);
    if ( v6 )
      __enable_irq();
    if ( (v7 & 0x10001) != 0 && a2 == (__mrc(15, 0, 13, 0, 3) & 0xFFFFFFC0) )
      return 0;
    if ( *(_DWORD *)(a2 + 1056) )
      return sub_5235E0();
    v9 = *(_DWORD **)(*(_DWORD *)(a2 + 336) + 288);
    __dmb(0xBu);
    if ( !v9 )
      return 0;
    if ( a1 == 2 )
    {
      v10 = (_DWORD *)v9[98];
LABEL_13:
      if ( !v10 )
        return 0;
      v12 = v10[176];
      v13 = v10[177];
      v14 = v10[178];
      v15 = v10[179];
LABEL_25:
      *(_DWORD *)a3 = v12;
      *(_DWORD *)(a3 + 4) = v13;
      *(_DWORD *)(a3 + 8) = v14;
      *(_DWORD *)(a3 + 12) = v15;
      return 0;
    }
    if ( a1 )
    {
      if ( a1 == 1 )
      {
        v10 = (_DWORD *)v9[97];
        goto LABEL_13;
      }
      if ( a1 == 3 )
      {
        v10 = (_DWORD *)v9[99];
        goto LABEL_13;
      }
      if ( a1 != 4 )
        return 0;
    }
    v11 = v9 + 176;
    v12 = v9[176];
    v13 = v9[177];
    v14 = v9[178];
    v15 = v11[3];
    goto LABEL_25;
  }
  return -1073741584;
}
