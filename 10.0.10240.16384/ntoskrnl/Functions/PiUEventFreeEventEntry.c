// PiUEventFreeEventEntry 
 
unsigned int __fastcall PiUEventFreeEventEntry(_DWORD *a1)
{
  unsigned int v2; // r0
  unsigned int v3; // r0
  unsigned int result; // r0

  v2 = a1[3];
  if ( v2 )
    ExFreePoolWithTag(v2);
  v3 = a1[2];
  if ( v3 )
    ExFreePoolWithTag(v3);
  if ( a1[6] )
    result = sub_7C1260();
  else
    result = ExFreePoolWithTag((unsigned int)a1);
  return result;
}
