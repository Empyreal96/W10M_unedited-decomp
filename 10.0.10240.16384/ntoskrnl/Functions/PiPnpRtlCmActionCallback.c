// PiPnpRtlCmActionCallback 
 
int __fastcall PiPnpRtlCmActionCallback(int a1, int a2, int a3, int a4, int a5, int *a6)
{
  int v6; // r5
  int v10; // r0
  int v11; // r0

  v6 = -1073741822;
  if ( a4 != 9 )
  {
    if ( (unsigned int)(a4 - 2) <= 0xF )
      __asm { ADD             PC, R3 }
    return v6;
  }
  if ( a5 != 1 )
  {
    if ( *a6 >= 0 || *a6 == -1073741275 )
      PiDmObjectUpdateCachedCmProperty(a3, a2);
    return 0;
  }
  if ( (a6[7] & 0x10000) != 0 )
    goto LABEL_9;
  v10 = PiDmObjectGetCachedCmProperty(a3, a2, a3, a6[3], a6[4], a6[5], a6[6]);
  if ( v10 < 0 && v10 != -1073741789 && v10 != -1073741275 && v10 != -1073741772 )
  {
    v6 = 0;
LABEL_9:
    if ( !a6[2] )
    {
      v11 = CmMapCmObjectTypeToPnpObjectType(a3);
      PiPnpRtlCacheObjectBaseKey(a1, a2, v11, a6 + 2);
      return v6;
    }
    return v6;
  }
  *a6 = v10;
  return -1073741536;
}
