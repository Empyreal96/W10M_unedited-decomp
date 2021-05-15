// IoGetRelatedTargetDevice 
 
int __fastcall IoGetRelatedTargetDevice(int a1, _DWORD *a2)
{
  int result; // r0
  int v4; // [sp+0h] [bp-8h] BYREF

  v4 = 0;
  result = PnpGetRelatedTargetDevice(a1, &v4);
  if ( result >= 0 )
  {
    if ( v4 )
      *a2 = *(_DWORD *)(v4 + 16);
  }
  return result;
}
