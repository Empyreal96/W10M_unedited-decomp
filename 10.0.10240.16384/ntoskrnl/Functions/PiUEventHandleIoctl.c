// PiUEventHandleIoctl 
 
int __fastcall PiUEventHandleIoctl(_DWORD *a1)
{
  _DWORD *v2; // r0
  int v3; // r2
  int v4; // r0
  int v5; // r4

  v2 = (_DWORD *)a1[24];
  v3 = v2[4];
  if ( v3 == 4655104 )
  {
    v4 = PiUEventHandleRegistration(v2[7], a1[3], v2[3], v2[2]);
    goto LABEL_3;
  }
  if ( v3 == 4655108 )
  {
    v4 = PiUEventHandleGetEvent(v2[7], (_DWORD *)a1[3], 4655108, v2[2], (int)(a1 + 6));
    goto LABEL_3;
  }
  if ( v3 != 4655112 )
  {
    if ( v3 != 4655116 )
    {
      v5 = -1073741637;
      goto LABEL_4;
    }
    v4 = PiUEventHandleUnregisterClient(v2[7]);
LABEL_3:
    v5 = v4;
LABEL_4:
    a1[6] = v5;
    IofCompleteRequest((int)a1, 0);
    return v5;
  }
  return sub_7C2424((int)v2);
}
