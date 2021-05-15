// ViThunkAdjustExportAddressIfHooked 
 
int __fastcall ViThunkAdjustExportAddressIfHooked(_DWORD *a1, unsigned __int16 *a2, int *a3, int a4)
{
  int *v4; // r5
  int v5; // r4
  int v6; // r7
  int v7; // r6
  unsigned int *v10; // r9
  int v11; // r2
  int v13; // [sp+0h] [bp-30h]
  int v14; // [sp+8h] [bp-28h] BYREF
  unsigned int *v15; // [sp+Ch] [bp-24h]

  v4 = a3;
  v5 = *a3;
  v6 = 0;
  v7 = 0;
  v13 = a4;
  v10 = 0;
  v15 = 0;
  if ( v5 )
  {
    while ( 1 )
    {
      v11 = v4[2];
      if ( v11 == *a1 )
        break;
      if ( !v11 )
      {
        if ( !v6 )
        {
          while ( RtlUnicodeStringToAnsiString((unsigned __int16 *)&v14, a2, 1, a4) < 0 )
            KeDelayExecutionThread(0, 0, (unsigned int *)ViShortTime);
          v10 = v15;
          v6 = 1;
        }
        if ( !strcmp(*v4, v10) )
          break;
        a4 = v13;
      }
      v4 = (int *)((char *)v4 + a4);
      if ( !*v4 )
        goto LABEL_14;
      a4 = v13;
    }
    v7 = 1;
    *a1 = v4[1];
LABEL_14:
    if ( v6 )
      RtlFreeAnsiString(&v14);
  }
  return v7;
}
