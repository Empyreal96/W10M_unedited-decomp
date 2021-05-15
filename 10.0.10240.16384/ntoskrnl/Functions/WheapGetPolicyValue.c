// WheapGetPolicyValue 
 
int __fastcall WheapGetPolicyValue(unsigned int a1, int *a2)
{
  bool v3; // zf
  int *v4; // r3
  int v5; // r3
  char *v6; // r3

  if ( a1 >= 7 )
    return -1073741811;
  switch ( a1 )
  {
    case 0u:
      v6 = &WheapPolicyDisableOffline;
      goto LABEL_17;
    case 1u:
      v6 = &WheapPolicyMemPersistOffline;
      goto LABEL_17;
    case 2u:
      v6 = &WheapPolicyMemPfaDisable;
LABEL_17:
      v3 = *v6 == 0;
LABEL_18:
      v5 = !v3;
      goto LABEL_21;
    case 3u:
      v4 = &WheapPolicyMemPfaPageCount;
      goto LABEL_12;
    case 4u:
      v4 = &WheapPolicyMemPfaThreshold;
LABEL_12:
      v5 = *v4;
LABEL_21:
      *a2 = v5;
      return 0;
  }
  if ( a1 != 5 )
  {
    v3 = WheaRegPolicyIgnoreDummyWrite == 0;
    goto LABEL_18;
  }
  *a2 = _rt_udiv64((unsigned int)dword_989680, WheapPolicyMemPfaTimeout);
  return 0;
}
