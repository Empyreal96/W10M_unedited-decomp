// sub_96FBF0 
 
void sub_96FBF0()
{
  _DWORD *v0; // r5

  if ( WheapInitializeErrorSource(v0) < 0 )
  {
    ExFreePoolWithTag((unsigned int)v0);
    JUMPOUT(0x963C30);
  }
  JUMPOUT(0x963C1E);
}
