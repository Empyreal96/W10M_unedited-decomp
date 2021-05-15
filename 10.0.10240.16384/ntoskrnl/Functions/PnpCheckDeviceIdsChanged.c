// PnpCheckDeviceIdsChanged 
 
int __fastcall PnpCheckDeviceIdsChanged(unsigned int a1, int a2, unsigned __int16 *a3, int a4, char a5, _BYTE *a6)
{
  int v9; // r8
  int v11; // r0
  unsigned int v12; // r9
  int v13; // r5
  unsigned int v14; // r10
  unsigned __int16 *v15; // r8
  unsigned __int16 *v16; // r7
  unsigned int v17; // r3
  int v18; // r0
  unsigned __int16 *v19; // r6
  unsigned int v20; // [sp+10h] [bp-30h] BYREF
  int v21; // [sp+14h] [bp-2Ch]
  unsigned int v22; // [sp+18h] [bp-28h]
  int v23; // [sp+1Ch] [bp-24h] BYREF
  unsigned int v24; // [sp+20h] [bp-20h]

  v24 = a4;
  v22 = a1;
  if ( a5 )
    v9 = 2;
  else
    v9 = 3;
  *a6 = 0;
  v21 = 0;
  if ( !a2 )
    return sub_7CB6EC();
  v20 = 512;
  v11 = ExAllocatePoolWithTag(1, 512, 1970499664);
  v12 = v11;
  if ( v11 )
  {
    v13 = CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(a1 + 24), a2, v9, (int)&v23, v11, (int)&v20);
    if ( v13 != -1073741789 )
    {
LABEL_7:
      if ( v13 < 0 )
      {
        if ( v13 == -1073741275 )
        {
          v13 = 0;
          if ( a3 )
          {
            *a6 = 1;
            while ( *a3 )
              a3 += wcslen(a3) + 1;
          }
        }
      }
      else if ( v23 == 7 )
      {
        v14 = v20;
        if ( a3 && v24 == v20 )
        {
          v15 = a3;
          v16 = (unsigned __int16 *)v12;
          if ( *a3 )
          {
            while ( *v16 )
            {
              v22 = wcslen(v15) + 1;
              v17 = wcslen(v16) + 1;
              v24 = v17;
              if ( v22 != v17 || RtlCompareUnicodeStrings(v15, v22, (int)v16, v17, 1) )
              {
                *a6 = 1;
                break;
              }
              v15 += v22;
              v16 += v24;
              if ( !*v15 )
                break;
            }
          }
          if ( !*a6 && (*v15 || *v16) )
            *a6 = 1;
        }
        else
        {
          *a6 = 1;
        }
        if ( *a6 )
        {
          v19 = (unsigned __int16 *)v12;
          if ( v14 )
          {
            do
            {
              if ( !*v19 )
                break;
              v19 += wcslen(v19) + 1;
            }
            while ( 2 * ((int)((int)v19 - v12) >> 1) < v14 );
          }
          if ( a3 )
          {
            while ( *a3 )
              a3 += wcslen(a3) + 1;
          }
        }
      }
      else
      {
        v13 = -1073741823;
      }
      ExFreePoolWithTag(v12);
      goto LABEL_21;
    }
    ExFreePoolWithTag(v12);
    v18 = ExAllocatePoolWithTag(1, v20, 1970499664);
    v12 = v18;
    if ( v18 )
    {
      v13 = CmGetDeviceRegProp(PiPnpRtlCtx, *(_DWORD *)(v22 + 24), a2, v9, (int)&v23, v18, (int)&v20);
      goto LABEL_7;
    }
  }
  v13 = -1073741670;
LABEL_21:
  if ( v21 )
    ZwClose();
  return v13;
}
