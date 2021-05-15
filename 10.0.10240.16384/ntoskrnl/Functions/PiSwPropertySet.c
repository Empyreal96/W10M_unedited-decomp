// PiSwPropertySet 
 
int __fastcall PiSwPropertySet(unsigned __int16 *a1, int a2, int a3, unsigned int a4)
{
  int *v6; // r6
  int v8; // r4
  unsigned int v9; // r5
  int v10; // r0
  int result; // r0
  int v12; // [sp+18h] [bp-28h] BYREF
  int v13[9]; // [sp+1Ch] [bp-24h] BYREF

  v12 = 0;
  v13[0] = 0;
  v6 = (int *)a3;
  v8 = PiPnpRtlBeginOperation(v13, a2, a3, 0);
  if ( v8 >= 0 && (v8 = PnpOpenObjectRegKey(PiPnpRtlCtx, (int)a1, a2, 7, 0, (int)&v12, 0, 0), v8 >= 0) && (v9 = 0, a4) )
  {
    while ( 1 )
    {
      v10 = PiPnpRtlSetObjectProperty(PiPnpRtlCtx, a1, a2, v12, v6[6], (unsigned int)v6, v6[7], v6[9], v6[8]);
      v8 = v10;
      if ( v10 == -1073741275 )
        break;
      if ( v10 >= 0 )
      {
        ++v9;
        v6 += 10;
        if ( v9 < a4 )
          continue;
      }
      goto LABEL_8;
    }
    result = sub_7E937C();
  }
  else
  {
LABEL_8:
    if ( v12 )
      ZwClose();
    if ( v13[0] )
      PiPnpRtlEndOperation(v13[0]);
    result = v8;
  }
  return result;
}
