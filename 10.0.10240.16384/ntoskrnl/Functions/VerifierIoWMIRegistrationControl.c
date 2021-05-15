// VerifierIoWMIRegistrationControl 
 
int __fastcall VerifierIoWMIRegistrationControl(int a1, int a2, int a3)
{
  int v5; // r3
  int vars4; // [sp+Ch] [bp+4h]

  v5 = VfSafeMode;
  if ( !VfSafeMode && a2 < 0 )
  {
    v5 = a2 & 0x7FFFFFFF;
    if ( (a2 & 0x7FFFFFFF) == 1 )
    {
LABEL_7:
      ViTargetWMIRegister(a1, vars4, a3, v5);
      goto LABEL_8;
    }
    if ( v5 == 2 )
    {
      ViTargetWMIDeregister(a1, vars4, a3, 2);
      goto LABEL_8;
    }
    if ( v5 == 3 )
    {
      ViTargetWMIDeregister(a1, vars4, a3, 3);
      goto LABEL_7;
    }
  }
LABEL_8:
  VfDevObjWMIRegistrationControl(a1, a2, a3, v5);
  return pXdvIoWMIRegistrationControl(a1, a2);
}
