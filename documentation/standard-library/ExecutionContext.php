<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>ExecutionContext - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


        <div class="code2">
            <p>Outline</p>
            <pre>
ExecutionContext := type {
    &lt;<a href="/documentation/standard-library/Scope.php">Scope</a>&gt; scope;
    &lt;Threading.Thread&gt; creatingThread;
    &lt;Runtime.StackTrace&gt; stack;
    &lt;CpuContext&gt; cpuContext;
    &lt;Void → Void&gt; continue; //cooperative multithreading entrypoint
};
            </pre>
        </div>
    

		<?php require('../../footer.php') ?>
	</body>
</html>