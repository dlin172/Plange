<meta charset='utf-8'/>
<meta name="viewport" content="width=device-width, initial-scale=0.6">
<html>
	<head>
		<title>SUPERSET_CHAIN - Syntax Pages - Plange</title>
		<link rel=StyleSheet href='../../css/general.css' type='text/css' />
	</head>
	<body>
		<?php require('../../header.php') ?>


		<p>One or more superset, proper superset, or equality relations</p>

		<div class="syntax">
			<p>syntax</p>
			<div><a href="/documentation/syntax/EXPRESSION.php">EXPRESSION</a> {<a href="/documentation/syntax/IC.php">IC</a>} <a href="/documentation/syntax/SUPERSET_CHAIN_LOOP.php">SUPERSET_CHAIN_LOOP</a></div>
		</div>
		<div class="code2">
			<p>Example</p>
			<pre>
S ⊃ T;
</pre>
		</div>		<div class="code2">
			<p>Example</p>
			<pre>
S ⊇ T ⊃ U = V;
</pre>
		</div>


		<?php require('../../footer.php') ?>
	</body>
</html>