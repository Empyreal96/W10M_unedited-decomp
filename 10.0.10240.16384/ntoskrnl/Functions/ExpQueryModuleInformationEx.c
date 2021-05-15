// ExpQueryModuleInformationEx 
 
int __fastcall ExpQueryModuleInformationEx(int a1, int a2, unsigned int a3, unsigned int *a4)
{
  unsigned int *v4; // r5
  unsigned int v5; // lr
  int v6; // r6
  int v7; // r1
  int v8; // r3
  unsigned int v9; // r2
  int *i; // r8
  unsigned int v11; // r3
  int v14; // [sp+0h] [bp-50h]
  unsigned int v15; // [sp+4h] [bp-4Ch]
  int v16; // [sp+Ch] [bp-44h]
  unsigned int v17; // [sp+2Ch] [bp-24h]

  v4 = a4;
  v5 = a3;
  v15 = a3;
  v6 = a2;
  v7 = 0;
  v16 = 0;
  v8 = 0;
  v14 = 0;
  v9 = 2;
  if ( v5 < 2 )
  {
    if ( v4 )
      *v4 = 2;
    v8 = -1073741820;
    v14 = -1073741820;
  }
  else
  {
    *(_WORD *)v6 = 0;
  }
  for ( i = (int *)PsLoadedModuleList; i != &PsLoadedModuleList; i = (int *)*i )
  {
    v11 = v9 + 300;
    if ( v9 + 300 < v9 )
      return -1073741823;
    v9 += 300;
    v17 = v11;
    if ( v15 >= v11 )
    {
      *(_WORD *)v6 = 300;
      ExpConvertLdrEntryToModuleInfo(i);
      *(_DWORD *)(v6 + 292) = 0;
      v6 += 300;
      *(_WORD *)v6 = 0;
      v9 = v17;
      v8 = v14;
      v7 = v16;
    }
    else
    {
      if ( v4 )
        *v4 = v11;
      v8 = -1073741820;
      v14 = -1073741820;
    }
    v16 = ++v7;
  }
  if ( v4 )
    *v4 = v9;
  return v8;
}
