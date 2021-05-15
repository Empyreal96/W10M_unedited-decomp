// MiInitializeMirroring 
 
int __fastcall MiInitializeMirroring(int a1)
{
  int result; // r0

  if ( a1 != 1
    || (KeInitializeEvent((int)&unk_634358, 1, 1),
        dword_634370 = (int)MiFinishResume,
        dword_634374 = -1,
        dword_634368 = 0,
        (dword_681264 & 1) != 0) )
  {
    result = sub_80E9F8();
  }
  else
  {
    result = 0;
  }
  return result;
}
