// SeIsAppContainerOrIdentifyLevelContext 
 
int __fastcall SeIsAppContainerOrIdentifyLevelContext(char *a1, _BYTE *a2)
{
  char *v2; // r4
  int v3; // r5
  int v4; // r6
  int v7; // [sp+18h] [bp-30h] BYREF
  char v8[4]; // [sp+1Ch] [bp-2Ch] BYREF
  char v9[40]; // [sp+20h] [bp-28h] BYREF

  v2 = a1;
  v3 = 0;
  v4 = 0;
  *a2 = 1;
  if ( !a1 )
  {
    SeCaptureSubjectContext(v9);
    v2 = v9;
    v4 = 1;
  }
  if ( SeAccessCheck(SeNullDaclSd, (int)v2, 0, 1, 0, 0, (int)SystemContextGenericMapping, 1, (int)v8, (int)&v7) )
    *a2 = 0;
  if ( v7 != -1073741790 )
    v3 = v7;
  if ( v4 )
    SeReleaseSubjectContext((int)v2);
  return v3;
}
