// ExFreeCacheAwarePushLock 
 
int __fastcall ExFreeCacheAwarePushLock(_DWORD *a1)
{
  _DWORD *v1; // r5
  int v2; // r4
  int *v3; // r6
  int v4; // t1

  v1 = a1;
  if ( *(_BYTE *)(*a1 + 4) )
    v2 = 1;
  else
    v2 = 32;
  v3 = a1;
  do
  {
    v4 = *v3++;
    ExFreePoolWithTag(v4);
    --v2;
  }
  while ( v2 );
  return ExFreePoolWithTag(v1);
}
