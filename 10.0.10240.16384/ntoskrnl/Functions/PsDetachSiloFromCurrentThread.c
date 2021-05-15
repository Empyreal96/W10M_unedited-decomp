// PsDetachSiloFromCurrentThread 
 
int __fastcall PsDetachSiloFromCurrentThread(int result)
{
  if ( result != -2 )
    result = sub_80A5A0();
  return result;
}
