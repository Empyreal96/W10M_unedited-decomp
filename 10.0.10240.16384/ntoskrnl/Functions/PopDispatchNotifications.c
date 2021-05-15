// PopDispatchNotifications 
 
int PopDispatchNotifications()
{
  char *v0; // r4
  int v1; // r5
  int result; // r0

  PopDispatchNotificationsToList(&PopPowerSettings);
  v0 = (char *)&PopSessionSpecificLists;
  v1 = 2;
  do
  {
    result = PopDispatchNotificationsToList(v0);
    v0 += 8;
    --v1;
  }
  while ( v1 );
  return result;
}
