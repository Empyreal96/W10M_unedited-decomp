// _PnpObjectRaiseDeleteEvent 
 
int __fastcall PnpObjectRaiseDeleteEvent(int result)
{
  int (__fastcall *v1)(int); // r4

  v1 = *(int (__fastcall **)(int))(result + 156);
  if ( v1 )
    result = v1(result);
  return result;
}
