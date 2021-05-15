// LdrpGetFromMUIMemCache 
 
int __fastcall LdrpGetFromMUIMemCache(int a1, int a2, _DWORD *a3, int a4)
{
  char v4; // r6
  int v7; // r10
  int v9; // r9
  int i; // r1
  _DWORD *v11; // r0
  _DWORD *v12; // r3
  int v13; // r2
  char v15; // [sp+8h] [bp-30h]
  int v16; // [sp+10h] [bp-28h]
  int varg_r1; // [sp+44h] [bp+Ch]
  _DWORD *varg_r2; // [sp+48h] [bp+10h]

  varg_r1 = a2;
  varg_r2 = a3;
  v4 = a4;
  v7 = a1;
  v16 = 0;
  v15 = 0;
  if ( (a4 & 0xC) == 0 || (a4 & 0xFFFFFFF3) != 0 || (a4 & 4) != 0 && !a2 )
    return 0;
  v9 = RtlImageNtHeader(a1 & 0xFFFFFFFC);
  if ( !v9 )
    return 0;
  if ( a3 )
    *a3 = 0;
  LdrpInitMuiCrits();
  KeWaitForSingleObject((unsigned int)&MuiMutex, 0, 0, 0, 0);
  for ( i = AlternateResourceModuleCount - 1; i >= 0; --i )
  {
    v11 = (_DWORD *)(AlternateResourceModules + 40 * i);
    if ( v11[1] == v7 )
    {
      if ( v11[3] != *(_DWORD *)(v9 + 88) )
      {
        v15 = 1;
        break;
      }
      if ( (v4 & 8) != 0 )
      {
        v12 = (_DWORD *)v11[2];
        if ( v12 )
        {
          v16 = v11[2];
          if ( v12 != (_DWORD *)-1 && *v12 != -20054323 )
          {
            v15 = 1;
            v16 = 0;
          }
          break;
        }
      }
      else if ( (v4 & 4) != 0 && a2 && *(unsigned __int16 *)v11 == a2 )
      {
        v13 = AlternateResourceModules + 40 * i;
        v16 = *(_DWORD *)(v13 + 16);
        if ( a3 )
          *a3 = *(_DWORD *)(v13 + 24);
        break;
      }
    }
  }
  KeReleaseMutant((unsigned int)&MuiMutex, 1, 0, 0);
  if ( v15 )
    LdrUnloadAlternateResourceModuleEx(a1);
  return v16;
}
