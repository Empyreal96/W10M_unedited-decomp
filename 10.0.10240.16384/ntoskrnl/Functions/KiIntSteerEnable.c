// KiIntSteerEnable 
 
int __fastcall KiIntSteerEnable(int a1)
{
  int v1; // r2
  int v2; // r2
  int v3; // r3
  int result; // r0
  unsigned int v5; // r1

  v1 = *(_DWORD *)(*(_DWORD *)a1 + 100);
  if ( !v1 )
    return -1073741637;
  if ( !*(_BYTE *)(v1 + 40) )
    return 0;
  v2 = *(_DWORD *)(v1 + 8);
  v3 = *(_DWORD *)(v2 + 96);
  if ( v3 == 2 || v3 != 1 )
    return -1073741637;
  *(_BYTE *)(v2 + 100) = 1;
  result = 0;
  __dmb(0xBu);
  do
    v5 = __ldrex((unsigned int *)&KiIntTrackRootEnabled);
  while ( __strex(1u, (unsigned int *)&KiIntTrackRootEnabled) );
  __dmb(0xBu);
  return result;
}
