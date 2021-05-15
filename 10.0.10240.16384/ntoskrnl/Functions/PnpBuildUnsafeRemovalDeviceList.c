// PnpBuildUnsafeRemovalDeviceList 
 
void __fastcall PnpBuildUnsafeRemovalDeviceList(int a1, int a2, _DWORD *a3)
{
  int v5; // r5
  int v6; // r4
  _BYTE *v7; // r0
  _WORD *v8; // r4
  int v9; // r5
  int v10; // r1
  int v11; // [sp+8h] [bp-28h] BYREF
  int v12; // [sp+Ch] [bp-24h] BYREF
  int v13; // [sp+10h] [bp-20h] BYREF
  int v14; // [sp+14h] [bp-1Ch]

  *a3 = 0;
  if ( a2 )
  {
    v5 = 0;
    v13 = 0;
    v14 = 0;
    while ( IopEnumerateRelations(a2, &v13, &v12, &v11, 0) )
    {
      if ( v11 )
      {
        v6 = *(_DWORD *)(*(_DWORD *)(v12 + 176) + 20);
        if ( !PnpIsBeingRemovedSafely((_DWORD *)v6, v11) )
        {
          if ( *(_DWORD *)(v6 + 24) )
            v5 += *(unsigned __int16 *)(v6 + 20) + 2;
        }
      }
    }
    if ( v5 )
    {
      v7 = (_BYTE *)ExAllocatePoolWithTag(1, v5 + 2, 1265659472);
      v8 = v7;
      *a3 = v7;
      if ( v7 )
      {
        memset(v7, 0, v5 + 2);
        v13 = 2;
        v14 = 0;
        while ( IopEnumerateRelations(a2, &v13, &v12, &v11, 0) )
        {
          if ( v11 )
          {
            v9 = *(_DWORD *)(*(_DWORD *)(v12 + 176) + 20);
            if ( !PnpIsBeingRemovedSafely((_DWORD *)v9, v11) )
            {
              v10 = *(_DWORD *)(v9 + 24);
              if ( v10 )
              {
                memmove((int)v8, v10, *(unsigned __int16 *)(v9 + 20));
                v8 += (*(unsigned __int16 *)(v9 + 20) >> 1) + 1;
              }
            }
          }
        }
        *v8 = 0;
      }
    }
  }
}
