// EtwpDeleteRegistrationObject 
 
int __fastcall EtwpDeleteRegistrationObject(int a1)
{
  int v2; // r0

  v2 = KeWaitForSingleObject((unsigned int)&EtwpNotificationMutex, 0, 0, 0, 0);
  if ( *(_DWORD *)(*(_DWORD *)a1 + 4) != a1 )
    __fastfail(3u);
  return sub_7D6BC0(v2);
}
