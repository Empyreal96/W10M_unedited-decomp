// SeQuerySigningPolicy 
 
int __fastcall SeQuerySigningPolicy(int a1, int a2, int a3, int a4, _BYTE *a5, _BYTE *a6, _BYTE *a7)
{
  int v10; // r6
  int v11; // r0
  int v13; // r3
  int v14; // r0
  char v15; // r3
  int varg_r0; // [sp+38h] [bp+8h]
  int varg_r1; // [sp+3Ch] [bp+Ch]
  int varg_r2; // [sp+40h] [bp+10h]

  varg_r0 = a1;
  varg_r1 = a2;
  varg_r2 = a3;
  v10 = RtlRunOnceExecuteOnce(&SeQuerySigningPolicyInit, SepInitQuerySigningPolicyExt, 0, 0);
  if ( v10 >= 0 )
  {
    if ( SeQuerySigningPolicyExtAllowed )
    {
      v11 = SeQuerySigningPolicyExt_0();
      v10 = v11;
      if ( v11 == -1073741637 )
        return sub_7D5200();
      if ( v11 >= 0 )
        goto LABEL_6;
    }
    v10 = SepIsMinTCB(a2, a3, (unsigned __int8)a4, a5, a6, a7, a7);
    if ( v10 >= 0 || (v10 = SeQuerySigningPolicyWorker(a1, a2, a3, (unsigned __int8)a4, a5, a6, a7), v10 >= 0) )
    {
LABEL_6:
      v13 = *a7 & 7;
      if ( v13 == 1 )
      {
        *a5 |= 0x30u;
      }
      else if ( v13 == 2 )
      {
        *a5 |= 0x10u;
        *a6 |= 0x10u;
      }
      if ( v10 >= 0 )
      {
        v14 = (unsigned __int8)*a5;
        if ( (v14 & 0xF) != 8
          && SeCompareSigningLevels(v14, 8)
          && ((SeCiDebugOptions & 4) != 0 || (SeCiDebugOptions & 2) != 0 && KdDebuggerEnabled && !KdDebuggerNotPresent) )
        {
          if ( !SeCompareSigningLevels((unsigned __int8)SeILSigningPolicy, 8) && (*a7 & 7) != 0 )
          {
            *a5 = *a5 & 0x30 | 8;
            if ( SeCompareSigningLevels(8, (unsigned __int8)*a6) )
              return v10;
            v15 = *a6 & 0x30 | 8;
            goto LABEL_20;
          }
          *a5 = SeILSigningPolicy & 0xF | *a5 & 0x30;
          if ( !SeCompareSigningLevels((unsigned __int8)SeILSigningPolicy, (unsigned __int8)*a6) )
          {
            v15 = SeILSigningPolicy & 0xF | *a6 & 0x30;
LABEL_20:
            *a6 = v15;
            return v10;
          }
        }
      }
    }
  }
  return v10;
}
