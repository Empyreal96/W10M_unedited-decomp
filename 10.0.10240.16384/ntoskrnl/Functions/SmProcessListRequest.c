// SmProcessListRequest 
 
int __fastcall SmProcessListRequest(int a1, unsigned int a2, unsigned int a3, unsigned int *a4, char a5)
{
  unsigned int v5; // r4
  unsigned int v6; // r8
  _BYTE *v7; // r0
  int v8; // r5
  int v9; // r4
  _BYTE *v10; // r0
  unsigned int v11; // r6
  unsigned int v13; // [sp+4h] [bp-2Ch]
  unsigned int *v14; // [sp+8h] [bp-28h]
  int v15; // [sp+Ch] [bp-24h]

  v14 = a4;
  v5 = a3;
  v13 = a3;
  v6 = a2;
  v15 = a1;
  v7 = (_BYTE *)SmAlloc(4228, 1380740467);
  v8 = (int)v7;
  if ( v7 )
  {
    v10 = memset(v7, 0, 4228);
    if ( v5 < 0x84 )
      goto LABEL_4;
    if ( a5 )
    {
      if ( (v6 & 3) != 0 )
        ExRaiseDatatypeMisalignment(v10);
      if ( v6 >= MmUserProbeAddress )
        *(_BYTE *)MmUserProbeAddress = 0;
      *(_BYTE *)v6 = *(_BYTE *)v6;
      *(_BYTE *)(v6 + 128) = *(_BYTE *)(v6 + 128);
    }
    memmove(v8, v6, 0x84u);
    if ( (*(_WORD *)(v8 + 2) & 1) != 0 )
    {
      if ( a5 )
        ProbeForWrite(v6, 4228, 4);
      v11 = 4228;
    }
    else
    {
      v11 = 132;
    }
    if ( v13 == v11 )
    {
      if ( (unsigned __int8)*(_DWORD *)v8 != 2 || *(_BYTE *)(v8 + 1) || (*(_DWORD *)v8 & 0xFFFE0000) != 0 )
      {
        v9 = -1073741811;
      }
      else
      {
        v9 = SmKmGetStoreList(v15, v8);
        if ( v9 >= 0 )
        {
          if ( (*(_WORD *)(v8 + 2) & 1) == 0 || (v9 = SmProcessListRequestExtended(v15), v9 >= 0) )
          {
            memmove(v6, v8, v11);
            *v14 = v11;
          }
        }
      }
    }
    else
    {
LABEL_4:
      v9 = -1073741306;
    }
  }
  else
  {
    v9 = -1073740716;
  }
  if ( v8 )
    ST_STORE<SM_TRAITS>::StDmSparseBitmapFree(v8);
  return v9;
}
