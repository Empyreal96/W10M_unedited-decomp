// WheapSetPolicyValue 
 
int __fastcall WheapSetPolicyValue(unsigned int a1, unsigned int *a2)
{
  unsigned int v3; // r5
  __int16 **v4; // r2
  __int16 *v5; // r6
  int *v6; // r3
  bool v7; // zf
  int v8; // r2
  char *v9; // r3

  if ( a1 >= 7 )
    return -1073741811;
  v3 = *a2;
  v4 = &(&WheaRegPolicyTable)[4 * a1];
  if ( *a2 < (unsigned int)v4[2] || v3 > (unsigned int)v4[3] )
    return -1073741811;
  v5 = v4[1];
  if ( *(_DWORD *)v5 != -1 )
  {
    v7 = *(_DWORD *)v5 == v3;
    goto LABEL_20;
  }
  switch ( a1 )
  {
    case 0u:
      v8 = v3 != 0;
      v9 = &WheapPolicyDisableOffline;
      goto LABEL_19;
    case 1u:
      v8 = v3 != 0;
      v9 = &WheapPolicyMemPersistOffline;
      goto LABEL_19;
    case 2u:
      v8 = v3 != 0;
      v9 = &WheapPolicyMemPfaDisable;
LABEL_19:
      v7 = v8 == (unsigned __int8)*v9;
      goto LABEL_20;
    case 3u:
      v6 = &WheapPolicyMemPfaPageCount;
      goto LABEL_15;
    case 4u:
      v6 = &WheapPolicyMemPfaThreshold;
      goto LABEL_15;
  }
  if ( a1 != 5 )
  {
    v6 = &WheaRegPolicyIgnoreDummyWrite;
LABEL_15:
    v7 = v3 == *v6;
    goto LABEL_20;
  }
  v7 = v3 == _rt_udiv64((unsigned int)dword_989680, WheapPolicyMemPfaTimeout);
LABEL_20:
  if ( !v7 )
  {
    *(_DWORD *)v5 = v3;
    WheaRegPolicyTableChanged[a1] = 1;
  }
  return 0;
}
