// PopUserPresentOverride 
 
int __fastcall PopUserPresentOverride(int a1)
{
  _BYTE *v2; // r0
  int v3; // r1
  int v4; // r4
  int v5; // r3

  v2 = PopAcquireAdaptiveLock(1);
  if ( a1 )
  {
    v5 = PopUserPresentOverrideCount + 1;
  }
  else
  {
    if ( !PopUserPresentOverrideCount )
    {
      v4 = -1073741811;
      goto LABEL_12;
    }
    v5 = PopUserPresentOverrideCount - 1;
  }
  PopUserPresentOverrideCount = v5;
  if ( v5 == 1 && a1 || !v5 && !a1 )
    PopEvaluateGlobalUserStatus((int)v2, v3, (int)&PopUserPresentOverrideCount, v5);
  v4 = 0;
LABEL_12:
  PopReleaseAdaptiveLock();
  return v4;
}
