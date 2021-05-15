// WmipGetGuidObjectInstanceInfo 
 
int __fastcall WmipGetGuidObjectInstanceInfo(int a1, int a2, _DWORD *a3, _DWORD *a4)
{
  _DWORD *v5; // r10
  int v7; // r5
  int v8; // r7
  int v9; // r9
  unsigned __int16 *v10; // r6
  _DWORD *v11; // r4
  _DWORD *v12; // r7
  _DWORD *v13; // t1
  int v14; // r10
  int v16; // [sp+8h] [bp-38h]
  unsigned __int16 *v17; // [sp+Ch] [bp-34h]
  int v19; // [sp+18h] [bp-28h] BYREF
  unsigned __int16 *v20; // [sp+1Ch] [bp-24h]

  v5 = a4;
  v7 = IoGetDeviceInstanceName(a2, (int)&v19);
  if ( v7 >= 0 )
  {
    v8 = *(_DWORD *)(a1 + 40);
    v16 = (unsigned __int16)v19 >> 1;
    v7 = -1073741162;
    v9 = 0;
    KeWaitForSingleObject((unsigned int)&WmipSMMutex, 0, 0, 0, 0);
    v10 = v20;
    if ( *(_DWORD *)(v8 + 20) )
    {
      v13 = *(_DWORD **)(v8 + 32);
      v12 = (_DWORD *)(v8 + 32);
      v11 = v13;
      if ( v13 != v12 )
      {
        while ( 1 )
        {
          if ( (v11[2] & 1) != 0 )
          {
            v17 = (unsigned __int16 *)(v11[12] + 4);
            v14 = (unsigned __int16)wcslen(v17);
            if ( !wcsnicmp((int)v17, v10, v16) && v14 == v16 + 1 && v17[v14 - 1] == 95 )
              break;
          }
          v11 = (_DWORD *)*v11;
          if ( v11 == v12 )
            goto LABEL_11;
        }
        v7 = 0;
        v9 = *(_DWORD *)v11[12];
LABEL_11:
        v5 = a4;
      }
    }
    KeReleaseMutex((int)&WmipSMMutex);
    if ( v7 >= 0 )
    {
      *a3 = v19;
      a3[1] = v10;
      v10 = 0;
      *v5 = v9;
      v20 = 0;
      v7 = 0;
    }
    if ( v10 )
      RtlFreeAnsiString(&v19);
  }
  return v7;
}
