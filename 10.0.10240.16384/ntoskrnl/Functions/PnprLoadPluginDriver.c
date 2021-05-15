// PnprLoadPluginDriver 
 
int __fastcall PnprLoadPluginDriver(unsigned int *a1, int a2)
{
  int v4; // r4
  unsigned int v5; // r6
  int v6; // r3
  int v7; // r2
  int v8; // r2
  int v9; // r2
  int v10; // r2
  unsigned int v12; // [sp+8h] [bp-20h] BYREF
  int v13; // [sp+Ch] [bp-1Ch] BYREF
  char v14[4]; // [sp+10h] [bp-18h] BYREF
  unsigned int v15; // [sp+14h] [bp-14h]

  v12 = 0;
  RtlInitUnicodeString((unsigned int)v14, 0);
  v4 = PnprGetPluginDriverImagePath((unsigned int)v14);
  if ( v4 >= 0 )
  {
    v4 = MmLoadSystemImage((int)v14, 0, 0, 2, (int *)&v12, &v13);
    v5 = v12;
    if ( v4 >= 0 )
    {
      memset((_BYTE *)a2, 0, 52);
      *(_DWORD *)(a2 + 4) = 1;
      *(_DWORD *)a2 = 52;
      v4 = (*(int (__fastcall **)(int, _DWORD))(v5 + 28))(a2, 0);
      if ( v4 >= 0 )
      {
        if ( *(_DWORD *)a2 >= 0x24u && *(_DWORD *)(a2 + 32) && *(_DWORD *)(a2 + 16) && *(_DWORD *)(a2 + 20) )
        {
          *a1 = v5;
          v4 = 0;
          goto LABEL_25;
        }
        v6 = PnprContext;
        v10 = *(_DWORD *)(PnprContext + 608);
        if ( !v10 )
          v10 = 4878;
        *(_DWORD *)(PnprContext + 608) = v10;
        v8 = *(_DWORD *)(v6 + 612);
        if ( !v8 )
          v8 = 9;
        v4 = -1073741637;
      }
      else
      {
        v6 = PnprContext;
        v9 = *(_DWORD *)(PnprContext + 608);
        if ( !v9 )
          v9 = 4862;
        *(_DWORD *)(PnprContext + 608) = v9;
        v8 = *(_DWORD *)(v6 + 612);
        if ( !v8 )
          v8 = 8;
      }
    }
    else
    {
      v6 = PnprContext;
      v7 = *(_DWORD *)(PnprContext + 608);
      if ( !v7 )
        v7 = 4848;
      *(_DWORD *)(PnprContext + 608) = v7;
      v8 = *(_DWORD *)(v6 + 612);
      if ( !v8 )
        v8 = 10;
    }
    *(_DWORD *)(v6 + 612) = v8;
    if ( v5 )
      MmUnloadSystemImage(v5);
  }
LABEL_25:
  if ( v15 )
    ExFreePoolWithTag(v15);
  return v4;
}
